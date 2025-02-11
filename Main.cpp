#include<iostream>
#include "Tree.h"

using namespace std;

/*int* getFileNums()
{
  char* input = new char[20];

        cout << "What file name \n";

	//gets a file name
	cin.ignore();
        cin.getline(input, 20);

	//gets the file you asked for
        ifstream inputFile(input);

	//this is a holder for the numbers being taken out of the file to be added after
        int* nums = new int[1000];
	//gets the current index nums
        int currentIndex = 0;
	//gets the current index in the current number array
        int currentNumberIndex = 0;
	//the numbers in the current number it is reading
        int currentNumber[4];
	//this is a holder for the final number read out
        int finalNumber = 0;
	//this is the amount of places in the number
        int amountOfPlaces = 0;
	//place holder for the char being read
        char currentChar;

        while (inputFile.get(currentChar)) 
        {
	//checks if it should start calculating the number it just read
            if (currentChar == ' ') 
            {
		//this starts adding up the current number
                for (int i = 0; i < amountOfPlaces; i++) 
                {
		//adds it by multiplying it by the place it is in and the number
                    finalNumber += currentNumber[i] * pow(10, amountOfPlaces - 1 - i);
		//resets the number
                    currentNumber[i] = -1;
                }

		//resets all the variables
                amountOfPlaces = 0;
                nums[currentIndex] = finalNumber;
                finalNumber = 0;
                currentIndex++;
                currentNumberIndex = 0;
            } //skips end line characters in case there is one
            else if (currentChar != '\n') 
            {
		//adds the current number to the array and goes to the next
                currentNumber[currentNumberIndex] = (int)currentChar - 48;
                amountOfPlaces++;
                currentNumberIndex++;
            }
	}
	return nums;
}*/

int main()
{
  Tree* tree= new Tree();
  tree->add(53, tree->root);
  tree->add(60, tree->root);
  cout << "added" << endl;

tree->add(21, tree->root);
tree->add(33, tree->root);
tree->add(50, tree->root);
tree->add(15, tree->root);
tree->add(45, tree->root);
 cout << "added" << endl;
 
 if(tree->search(tree->root, 8))
   cout << "found 8\n";
 
 tree->remove(nullptr, tree->root, 2);
 
 if(tree->search(tree->root, 2))
   cout << "found 2\n";
 
 if(tree->search(tree->root, 8))
   cout << "found 8\n";
 
 if(tree->search(tree->root, 4))
  cout << "found 4\n";

 tree->print();
}
