#pragma once

#include <string>
#include <utility>

namespace storm {

class PlotOptions {
public:
    explicit PlotOptions(std::string color = "b")
        : color_(std::move(color)) {}

    [[nodiscard]] const std::string& color() const noexcept {
        return color_;
    }

    [[nodiscard]] const std::string& marker() const noexcept {
        return marker_;
    }

    [[nodiscard]] const std::string& line_style() const noexcept {
        return line_style_;
    }

    [[nodiscard]] float line_width() const noexcept {
        return line_width_;
    }

    [[nodiscard]] float marker_size() const noexcept {
        return marker_size_;
    }

    PlotOptions& color(std::string value) {
        color_ = std::move(value);
        return *this;
    }

    PlotOptions& marker(std::string value) {
        marker_ = std::move(value);
        return *this;
    }

    PlotOptions& line_style(std::string value) {
        line_style_ = std::move(value);
        return *this;
    }

    PlotOptions& line_width(float value) noexcept {
        line_width_ = value;
        return *this;
    }

    PlotOptions& marker_size(float value) noexcept {
        marker_size_ = value;
        return *this;
    }

private:
    std::string color_{"b"};
    std::string marker_{"o"};
    std::string line_style_{"-"};
    float line_width_{1.5F};
    float marker_size_{10.0F};
};

} 
