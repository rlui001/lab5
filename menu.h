#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"
#include <vector>

using namespace std;

class Menu {
    private:    
        int history_index;
        vector<Command*> history;

    public:
        Menu() {
            //Base constructor to set up all necessary members
            history_index = -1;
        };
        void execute() {
            //Prints the current commands value (based on history_index), if no commands exist
            //print 0 by default
            if (history.size() == 0) {
                cout << "0\n";
            }
            else {
                cout << history.at(history_index)->execute();
                cout << endl;
            }
        };
        bool initialized() {
            //Return true if the history has been primed with a single op instruciton
            //This is necessary because that is the base of a calculation
            //will only return true after first input, which must e a number.
            //if first input is not a number, will return false. calculator.cpp keeps this in check
            if (history.size() != 0) {
                return true;
            }
            else {
                return false;
            }
        };
        void add_command(Command* cmd) {
            //Adds a command to history in the appropriate posiiton (based on history_index)
            if (history_index == history.size() - 1) {
                history.push_back(cmd);
                ++history_index;
            }
            else if (history.size() == 0) {
                 history.push_back(cmd);
                ++history_index;
            }
            else if (history_index > history.size() - 1) { // ERROR CASE
                cout << "INDEX IS PAST SIZE OF VECTOR\n";
            }
            else { //index is smaller than vector size, needs to adjust whole vector
                int i = 0;
                vector<Command*>::iterator it;
                it = history.begin();
                for (i = 0; i != history_index; ++i) {
                    ++it;
                }
                // iterator should now be at position to insert into vector
                history.insert(it+1, cmd);


               ++history_index;
            }

        };
        Command* get_command() {
            //Returns the command in history we are currently referring to (based on history_index)
            return history.at(history_index);
        };
        void undo() {
            //Moves to the last command in history (if possible)
            if (history.size() == 0) {
                cout << "Undo is not possible." << endl;
            }
            else if (history_index == 0) {
                cout << "Undo is not possible." << endl;
            }
            else {
                --history_index;
            }
            
        };
        void redo() {
            //Moves to the next command in history (if possible)
            if (history.size() == 0) {
                cout << "Redo is not possible." << endl;
            }
            else if (history_index == history.size() - 1) {
                cout << "Redo is not possible." << endl;
            }
            else if (history_index >= history.size()) {
                cout << "Redo is not possible." << endl;
            }
            else {
                ++history_index;
            }
        };
};

#endif //__MENU_CLASS__
