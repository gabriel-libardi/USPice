#ifndef __CIRCUIT_HPP__
#define __CIRCUIT_HPP__

#include <vector>
#include <unordered_map>
#include "component.hpp"
using namespace std;


struct pair {
    int node_1;
    int node_2;
};


class Circuit {
    /*****************************************************************
    This is the class of circuits. The vector matrix 'conections' is
    the adjancency list of (the graph that represents) the circuit.
    The map components maps each edge of the graph to its component.
    ******************************************************************/

    private:
        vector<vector<int>> conections;
        unordered_map<pair, vector<Component>> components;
    
    public:
        Circuit(vector<vector<int>>& conections, unordered_map<pair, Component>& components);
        Circuit();

        add_component(int node_plus, int node_minus, Component& new_component);

        vector<double>& DC_analysis();
        vector<double>& AC_analysis();
        vector<double>& fourier_analysis();
        vector<double>& noise_analysis();
        vector<double>& bias_point();
        vector<double>& sensitivity_analysis();
        vector<double>& transfer();
        vector<double>& transient_analysis();
};


#endif