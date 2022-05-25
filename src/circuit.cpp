#include "circuit.hpp"
#include "components.hpp"
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


Circuit::Circuit() = default;


Circuit::Circuit(vector<vector<int>>& conections, unordered_map<pair, Component>& components) {
    this->conections = conections;
    this->components = components;
}


Circuit::add_component(int node_plus, int node_minus, Component& new_component) {
    if ((node_plus > (this->conections).size()) || (node_minus > (this->conections).size())) {
        (this->conections).resize(max(node_plus, node_minus));
    }

    (this->conections[node_plus]).push_back(node_minus);
    (this->conections[node_minus]). push_back(node_plus);

    pair coordinates = {node_plus, node_minus};
    ((this->components)[coordinates]).push_back(new_component);
}