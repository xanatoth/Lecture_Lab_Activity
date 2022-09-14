/*
Lab Activity:  Write  a  program  that  prompts  the  user  to  enter  a  length  in  feet  and  inches  and  outputs  the  equivalent  length  in  centimeters.  If  the  user  enters  a  negative  number  or  a  nondigit  number,  throw  and  handle  an appropriate exception and prompt the user to enter another set of numbers.
*/


#include <iostream>
#include <stdexcept>

class lenght{
private:
    int feet;
    int inches;
public:
    void setFeetandInches(int footsies, int inch){
        try {//checks if foot value passed is < 0
            if (footsies < 0) {
                //sets inches if value passed is > 0
                if(inch > 0){ inches=inch;}
                throw std::invalid_argument("Input cannot be negative\n");
            }
            feet = footsies;
            setInches(inch);
        }
        //catches exception for values < 0
        catch(std::invalid_argument textException){
            std::cout << textException.what();
            int num=-1;
            while(num < 0){
                if(footsies < 0) {
                    std::cout << "Enter feet: ";
                    std::cin >> num;
                    if (num > 0) {feet = num;}
                }
                if(inch < 0){
                    std::cout << "\nEnter inches: ";
                    std::cin >> num;
                    if(num>0){inches=num;}
                }//if
            }//while
        }//catch
    }//function
    void setInches(int x){
        if(x<0){
            throw std::invalid_argument("Input cannot be negative");
        }
        inches = x;
    }
    float lengthToCentimeter(){
        return (feet*30.48)+(inches*2.54);
    }
    int getInches(){return inches;}
    int getFeet(){return feet;}
};

int main() {
    int feet,inches;
    lenght myLength;
    std::cout << "Enter length in feet and inches: ";
    //checks for invalid inputs and throws exception if found
    try {
        std::cin >>  feet >> inches;
        if(!std::cin.good()){
            throw std::invalid_argument("Input must be integer values!");
        }
    }
    //catches exception for invalid input
    catch (std::invalid_argument textException){
        while(!std::cin.good()){
            std::cout << textException.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Enter length in feet and inches: ";
            std::cin >>  feet >> inches;
        }
    }
    myLength.setFeetandInches(feet,inches);
    std::cout << "Feet: " << myLength.getFeet() << std:: endl;
    std::cout << "Inches: " << myLength.getInches() << std:: endl;
    std::cout<< "Converted to centimeters: "<< myLength.lengthToCentimeter();


    return 0;
}
