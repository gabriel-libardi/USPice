#ifndef __COMPONENTS_HPP__
#define __COMPONENTS_HPP__

#include <vector>
using namespace std;


class Component {
    /*****************************************************************
    This is the class of circuit components. The name of a component
    is its designator in PSPICE syntax, except for the following:

    - Transmission line coupling: name = 'k'
    - Stimulus devices: name = 'u'

    The parameters vector stores the particular values of a component.
    ******************************************************************/

    private:
        char name;
        vector<double> parameters;
    
    public:
        Component(char name, vector<double>& parameters);
        Component(char name, double *parameters);
};


#endif