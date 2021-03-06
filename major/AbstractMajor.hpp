#ifndef __ABSTRACTMAJOR_HPP__
#define __ABSTRACTMAJOR_HPP__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

class AbstractMajor {
    protected:
        string name;
        vector<string> requiredCourses;
    public:
        AbstractMajor() {}

        virtual string getName() { return name; };

        virtual vector<string> getRequiredCourses() { return requiredCourses; };
        
        void getRequirements() {
            ifstream fin("major/" + this->name + ".txt");
            
            if (!fin.is_open()) {
                throw std::invalid_argument("Error, requirements file for " + this->name + " not found.");
            }
            string temp;

            while(getline(fin, temp)) {
                requiredCourses.push_back(temp);
            }
        }
};

#endif //__ABSTRACTMAJOR_HPP__