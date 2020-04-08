#pragma once

#include "core/edge.hpp"

#include <limits>
#include <list>
#include <vector>

namespace georhiau {
namespace algo {

using edge_d = georhiau::core::edge<double, 2>;
using vertex_d = georhiau::core::vertex<double, 2>;

// very silly aglo to calculate Relative Neibourhood graph.
auto rng(const std::vector<vertex_d>& cloud) {
    std::list<edge_d> edges;
    // for each point in the cloud
    for (const auto& p : cloud) {
        // for each other point
        for (const auto& q : cloud) {
            if (p == q) continue;
            // calculate the distance between them
            auto d = georhiau::core::norm(p - q);
            auto min = std::numeric_limits<double>::max();
            for (const auto& x : cloud) {
                // if r is one of p or q then move on
                if (p == x || q == x) continue;
                auto xp = georhiau::core::norm(x - p);
                auto xq = georhiau::core::norm(x - q);
                auto max = std::max(xp, xq);
                if (max < min) min = max;
            }
            // add edge
            if (d < min) {
                auto e = edge_d(p, q);
                edges.push_back(e);
            }
        }
    }
    return edges;
}
}  // namespace algo
}  // namespace georhiau

