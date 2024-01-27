#include <iostream>
#include <vector>
#include <string>
#include <algorithm>		// this is for sorting
#include <ctime>		// this is for srand
#include <cstdlib>		// this is for rand

using namespace std;

vector < int >getNumbers ();	// generates the 5 random lottery numbers and sets up the powerball
void setPowerball (vector < int >&);	//genearates the powerball number and adds it to the vector
//void setPowerball provides a pass by reference because the function directly changes the input vector
void showNumbers (const vector < int >&);	// displays the randomized numbers
//getNumbers provies a pass by value because the vector is being copied while returned
int
main ()
{
  string num;
  srand (time (0));		//gives off random numbers

  do
    {
      cout << "How many lotto numbers do you want to generate? ";	//tells the user to type a number
      getline (cin, num);	//prints the number

      if (num != "n" && num != "N")
	{			//if the user types "n" or "N", the loop ends
	  int numDraws = stoi (num);
	  for (int draw = 0; draw < numDraws; ++draw)
	    {
	      vector < int >lotteryNumbers = getNumbers ();

	      //Line display the generated lottery numbers
	      showNumbers (lotteryNumbers);
	    }
	}

      cout << "Would you like to see more numbers? ('Y' or 'N') ";	//Asks the user if they would like to see more numbers
      getline (cin, num);

    }
  while (num == "Y" || num == "y");	//If the user types "y" or "Y", the loop starts over/continues

  return 0;
}

vector < int >
getNumbers ()
{
  vector < int >lotteryNumbers;

  // Generate 5 random lottery numbers in ascending order
  while (lotteryNumbers.size () < 5)
    {
      int number = rand () % 69 + 1;	// Generate a random number between 1 and 69

      //Line Checks for duplicates
      if (find (lotteryNumbers.begin (), lotteryNumbers.end (), number) ==
	  lotteryNumbers.end ())
	{
	  lotteryNumbers.push_back (number);
	}
    }

  //Line sorts the numbers in ascending order
  sort (lotteryNumbers.begin (), lotteryNumbers.end ());

  //Line sets the Powerball number
  setPowerball (lotteryNumbers);

  return lotteryNumbers;
}

void
setPowerball (vector < int >&lotteryNumbers)
{
  // Generatse the Powerball Number from 1 to 26
  int powerball = rand () % 26 + 1;

  // Adds the Powerball number to the vector
  lotteryNumbers.push_back (powerball);
}

void
showNumbers (const vector < int >&v)
{
  //Line displays the lotto numbers
  for (int i = 0; i < v.size () - 1; ++i)
    {
      cout << v[i] << " ";
    }

  //Line displays the Powerball number
  cout << "PB " << v.back () << endl;
}
