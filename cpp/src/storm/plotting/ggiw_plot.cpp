#include <storm/plotting/ggiw_plot.hpp>

#include <Eigen/Eigenvalues>

#include <cmath>
#include <cstddef>
#include <numbers>
#include <stdexcept>
#include <vector>

namespace storm {
namespace {

void validate_axes_and_mean(
    const matplot::axes_handle& axes,
    const GGIW2D& dist
) {
    if (!axes) {
        throw std::invalid_argument("Cannot plot a GGIW2D on null axes");
    }

    if (dist.mean().size() < 2) {
        throw std::invalid_argument(
            "A GGIW2D mean needs at least two elements for a 2D plot"
        );
    }
}

}

void plot_mean(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options
) {
    validate_axes_and_mean(axes, dist);

    const Vector& mean = dist.mean();
    auto marker = axes->scatter(
        std::vector<double>{mean(0)},
        std::vector<double>{mean(1)}
    );
    marker->marker(options.marker())
        .marker_color(options.color())
        .marker_face_color(options.color())
        .line_width(options.line_width())
        .marker_size(options.marker_size())
        .marker_face(true);
}

void plot_mean_extent(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options
) {
    validate_axes_and_mean(axes, dist);

    const Vector& mean = dist.mean();
    const Matrix& shape = dist.IWshape();

    if (shape.rows() != 2 || shape.cols() != 2) {
        throw std::invalid_argument(
            "A 2D extent plot requires a 2-by-2 inverse-Wishart shape matrix"
        );
    }

    constexpr double spatial_dimension = 2.0;
    // GGIW random-matrix convention: E[X] = V / (v - 2d - 2).
    const double denominator =
        dist.IWdof() - 2.0 * spatial_dimension - 2.0;

    if (denominator <= 0.0) {
        throw std::domain_error(
            "The inverse-Wishart mean requires v > 2d + 2"
        );
    }

    const Matrix expected_extent = shape / denominator;
    const Eigen::SelfAdjointEigenSolver<Matrix> eigensolver(expected_extent);

    if (eigensolver.info() != Eigen::Success ||
        (eigensolver.eigenvalues().array() <= 0.0).any()) {
        throw std::domain_error(
            "The expected extent must be symmetric positive definite"
        );
    }

    const Matrix ellipse_transform =
        eigensolver.eigenvectors() *
        eigensolver.eigenvalues().cwiseSqrt().asDiagonal();

    constexpr std::size_t point_count = 200;
    std::vector<double> x;
    std::vector<double> y;
    x.reserve(point_count + 1);
    y.reserve(point_count + 1);

    for (std::size_t index = 0; index <= point_count; ++index) {
        const double angle =
            2.0 * std::numbers::pi * static_cast<double>(index) /
            static_cast<double>(point_count);

        Vector unit_circle(2);
        unit_circle << std::cos(angle), std::sin(angle);

        const Vector point =
            mean.head(2) + ellipse_transform * unit_circle;
        x.push_back(point(0));
        y.push_back(point(1));
    }

    auto ellipse = axes->plot(x, y);
    ellipse->line_style(options.line_style())
        .color(options.color())
        .line_width(options.line_width());
}

void plot(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options
) {
    if (!axes) {
        throw std::invalid_argument("Cannot plot a GGIW2D on null axes");
    }

    const bool was_holding = axes->hold();
    axes->hold(true);

    try {
        plot_mean_extent(axes, dist, options);
        plot_mean(axes, dist, options);
        axes->axis(matplot::equal);
    } catch (...) {
        axes->hold(was_holding);
        throw;
    }

    axes->hold(was_holding);
}

} 
