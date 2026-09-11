#pragma once

#include <matplot/matplot.h>
#include <storm/models/GGIW.hpp>

namespace storm {
    matplot::figure_handle plot(const storm::GGIW& dist);
}
