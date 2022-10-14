#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy", 72, 45), _target("unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy", 72, 45),  _target(target){
}

void RobotomyRequestForm::action() const{
    std::cout << "Makes some drilling noises\n";
    int i = 1;
    while (i <= 50)
    {
        std::cout<< "...";
        if(i % 10 == 0)
            std::cout<< "\n";
        i++;
    }
    std::cout << getTarget() + " has been robotomizedsuccessfully 50% of the time\n";
    while (i < 70)
    {
        std::cout<< "...";
        if(i % 10 == 0)
            std::cout<< "\n";
        i++;
    }
    std::cout << "         ";
    std::cout << " robotomy failed successfully...\n";
}


RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &srcForCopy){
    *this = srcForCopy;
}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &srcForAssigment){
    _target.copy((char *)&srcForAssigment.getName()[0], srcForAssigment.getName().length());
    this->_isSigned = srcForAssigment.getIsSinged();     
    return *this;
}

void RobotomyRequestForm::print(){
    std::cout<< "RobotomyRequestForm " + this->message();
}

std::string RobotomyRequestForm::getTarget()const {
    return _target;
}