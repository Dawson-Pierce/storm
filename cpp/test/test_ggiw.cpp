#include <storm/models/GGIW.hpp>
#include <storm/plotting/ggiw_plot.hpp>

#include <cmath>
#include <iostream>

namespace {

bool nearly_equal(double lhs, double rhs, double tolerance = 1e-12) {
    return std::abs(lhs - rhs) <= tolerance;
}

} // namespace

int main() {
    storm::Vector mean(4);
    mean << 10.0, 20.0, 1.5, -0.5;

    storm::Matrix covariance = storm::Matrix::Identity(4, 4);

    storm::Matrix extent(2, 2);
    extent << 9.0, 1.0,
              1.0, 4.0;

    storm::GGIW distribution(
        6.0,
        2.0,
        mean,
        covariance,
        10.0,
        extent
    );

    auto figure = storm::plot(distribution);
    figure->show();

    const bool passed =
        nearly_equal(distribution.alpha(), 6.0) &&
        nearly_equal(distribution.beta(), 2.0) &&
        distribution.mean().isApprox(mean) &&
        distribution.covariance().isApprox(covariance) &&
        nearly_equal(distribution.IWdof(), 10.0) &&
        distribution.IWshape().isApprox(extent);

    if (!passed) {
        std::cerr << "GGIW construction/accessor test failed\n";
        return 1;
    }

    std::cout << "GGIW construction/accessor test passed\n";
    return 0;
}
