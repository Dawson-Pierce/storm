#pragma once

#include <matplot/matplot.h>
#include <storm/models/GGIW2D.hpp>
#include <storm/plotting/plot_options.hpp>

namespace storm {

void plot_mean(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options = PlotOptions{}
);

void plot_mean_extent(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options = PlotOptions{}
);

void plot(
    const matplot::axes_handle& axes,
    const GGIW2D& dist,
    const PlotOptions& options = PlotOptions{}
);

} 