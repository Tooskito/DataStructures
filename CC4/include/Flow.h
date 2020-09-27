/**
 *  @author Jonathan Abbott
 *  @date   September 27, 2020
 *  Contains the implementation for my solution for Prob1 of CC4 for CSE 20312.
 */
#ifndef FLOW_H
#define FLOW_H

#include <iostream> // std::cout, std::endl
#include <utility>  // std::pair
#include <vector>   // std::vector
#include <queue>    // std::queue

/* Typedefs for quality-of-life. */
typedef std::pair<int, int> p_t;
typedef std::vector<int> v_t;
typedef std::vector<p_t> vp_t;
typedef std::vector<v_t> vv_t;
typedef std::queue<p_t> qp_t;

// So that std::cout << vv_t will output all vectors in vector.
std::ostream& operator<< (std::ostream& os, const vv_t& map) {
    for (const v_t& row : map) {
        std::cout << "( ";
        for (const int& val : row)
            std::cout << val << " ";
        std::cout << ")" << std::endl;
    }
    return os;
}

// So that std::cout << vp_t will output all pairs in vector.
std::ostream& operator<< (std::ostream& os, const vp_t& map) {
    for (const p_t& row : map)
        std::cout << "( " << row.first << " " << row.second << " )" << std::endl;
    return os;
}

// To keep this code compartmentalized.
namespace Flow {

    /**
     *  Given a map, a floodMap, an x and y, floods from top and left edges
     *  if not already flooded in floodMap.
     */
    void PacificAtlantic_BFS(const vv_t& map, vv_t& floodMap, int x, int y) {
        int m = (int)map.size(), n = (int)map.at(0).size(); 
        vp_t dirs{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // Move down, right, up, and left.
        qp_t queue;
        queue.push({x, y});
        while (not queue.empty()) {
            p_t elem = queue.front();
            queue.pop();
            int i = elem.first, j = elem.second;
            for (const p_t& dir : dirs) {
                int newi = i + dir.first, newj = j + dir.second;
                // Check if i, j + direction is still within bounds, is not already flooded, and if it
                // even can be flooded.
                if (0 <= newi and newi < m and 0 <= newj and newj < n // If new index is within bounds,
                    and floodMap.at(newi).at(newj) != 1 // And new index isn't already flooded,
                    and map.at(i).at(j) <= map.at(newi).at(newj)) 
                {
                        floodMap.at(newi).at(newj) = 1;
                        queue.push({newi, newj});
                }
            }
        }
    }

    /**
     *  Given a map of heights, shows whether or not water flowing from the bottom and right
     *  edges can reach the top or left edges.
     */
    vp_t PacificAtlantic(const vv_t& map) {
        int m = (int)map.size(), n = (int)map.at(0).size();
        vp_t res;
        // Create floodMap of 1s and 0s.
        // 1s are where water can flow from there to the top-left edge. 0s are not.
        vv_t floodMap(m, v_t(n, 0));
        for (int i = 0; i < m; ++i) {
            floodMap.at(i).at(0) = 1;
            PacificAtlantic_BFS(map, floodMap, i, 0);
        }
        for (int j = 0; j < n; ++j) {
            floodMap.at(0).at(j) = 1;
            PacificAtlantic_BFS(map, floodMap, 0, j);
        }
        // Check bottom-right edges for solution.
        for (int i = 0; i < m; ++i)
            if (floodMap.at(i).at(n - 1) == 1)
                res.push_back({i, n - 1});
        for (int j = 0; j < n; ++j)
            if (floodMap.at(m - 1).at(j) == 1)
                res.push_back({m - 1, j});
        return res;
    }
}
#endif