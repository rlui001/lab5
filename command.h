#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
    protected:
        Base* root;
    
    public:
        Command() { };
        double execute() {
            return root->evaluate();
        };
        Base* get_root() {
            return root;
        };
};

class OpCommand : public Command {
    //OpCommand Code Here
    public:

        OpCommand(int x) {
           root = new Op(x);
        }

};

class AddCommand : public Command {
    Base* left;
    Base* right;

    public:
        AddCommand(Command* cmd, double val) {
            left = cmd->get_root();
            right = new Op(val);
            root = new Add(left, right);
        }
       
};

class SubCommand : public Command {
    //SubCommand Code Here
    Base* left;
    Base* right;

    public:
        SubCommand(Command*  cmd, double val) {
            left = cmd->get_root();
            right = new Op(val);
            root = new Sub(left, right);
        }

};

class MultCommand : public Command {
    //MultCommand Code Here
    Base* left;
    Base* right;

    public:
        MultCommand(Command* cmd, double val) {
            left = cmd->get_root();
            right = new Op(val);
            root = new Mult(left, right);
        }
};

class SqrCommand : public Command {
    //SqrCommand Code Here
    public:
        SqrCommand(Command* cmd) {
            root = new Sqr(cmd->get_root());
        }
};

#endif //__COMMAND_CLASS__
