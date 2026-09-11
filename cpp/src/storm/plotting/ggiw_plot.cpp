#include <storm/plotting/ggiw_plot.hpp>

#include <vector>

namespace storm {

    matplot::figure_handle plot(const GGIW& dist) {
        auto figure = matplot::figure(true);
        const Vector& mean = dist.mean();

        figure->current_axes()->scatter(
            std::vector<double>{mean(0)},
            std::vector<double>{mean(1)}
        );

        return figure;
    }

}