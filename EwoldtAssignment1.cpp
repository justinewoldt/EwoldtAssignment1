#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

const double PI = 3.14159265358979323846;
string fileDestination; //destination of filepath
double linesMean, linesVariance, linesSD;
double numberOfLines = 0;
double numberOfChars = 0;
double numberOfA, numberOfC, numberOfT, numberOfG, numberofPairs;
double AAs, ACs, ATs, AGs, CCs, CAs, CTs, CGs, TTs, TAs, TCs, TGs, GGs, GAs, GCs, GTs;
double probAA, probAC, probAT, probAG, probCC, probCA, probCT, probCG, probTT, probTA, probTC, probTG, probGG, probGA, probGC, probGT, probA, probC, probT, probG;

void fileStream(string destination) // take destination and open and read file
{
  string line; // each line of the text file
  ifstream myfile; // variable for my file
  myfile.open(destination); //open the file
  while(getline(myfile, line)) // iterate through the entire file
  {
    for(int i = 0; i < line.length(); i++) // iterate through each line of the file
    {
      char currentChar = line.at(i);
      switch(currentChar) // check for characters
      {
        case 'A': numberOfA++;
                  break;
        case 'a': numberOfA++;
                  break;
        case 'c': numberOfC++;
                  break;
        case 'C': numberOfC++;
                  break;
        case 'T': numberOfT++;
                  break;
        case 't': numberOfT++;
                  break;
        case 'G': numberOfG++;
                  break;
        case 'g': numberOfG++;
                  break;
      }
    }
    numberOfLines++; // increment for each line that it iterates over
    numberOfChars += line.length(); // counts each character from each line
  }
  myfile.close(); //close
}
void calculateMean(double lines, double chars) // calculates mean
{
  double mean = chars/lines;
  linesMean = mean;
}

void calculateVariance(string destination) // calculates variance
{
  double summation = 0;
  string line;
  ifstream myfile;
  myfile.open(destination);
  while(getline(myfile, line)) // open and read file
  {
    summation += pow((line.length()-linesMean), 2);
  }
  linesVariance = summation/(numberOfLines - 1);
  myfile.close();
}
void calculateSD(double variance) // calculate standard deviation
{
  linesSD = sqrt(variance);
}
void findPairs(string destination) // count all the pairs from the file
{
  string line;
  ifstream myfile;
  myfile.open(destination);
  while(getline(myfile,line))
  {
    for(int i = 0; i < line.length(); i++)
    {
      if (i%2 != 0)
      {
        string testString = "";
        int previous = i-1;
        char previousChar = line.at(previous);
        char currentChar = line.at(i);
        previousChar = toupper(previousChar);
        currentChar = toupper(currentChar);
        if(previousChar == 'A')
        {
          switch(currentChar)
          {
            case 'A':AAs++;
            break;
            case 'C':ACs++;
            break;
            case 'T':ATs++;
            break;
            case 'G':AGs++;
            break;
          }
        }
        else if(previousChar == 'C')
        {
          switch(currentChar)
          {
            case 'A':CAs++;
            break;
            case 'C':CCs++;
            break;
            case 'T':CTs++;
            break;
            case 'G':CGs++;
            break;
          }
        }
        else if(previousChar == 'T')
        {
          switch(currentChar)
          {
            case 'A':TAs++;
            break;
            case 'C':TCs++;
            break;
            case 'T':TTs++;
            break;
            case 'G':TGs++;
            break;
          }
        }
        else
        {
          switch(currentChar)
          {
            case 'A':GAs++;
            break;
            case 'C':GCs++;
            break;
            case 'T':GTs++;
            break;
            case 'G':GGs++;
            break;
          }

        }
        numberofPairs++;
      }


    }
  }
  myfile.close();
}
void findPairProbability() // pair relative probability math and assign
{
  probAA = AAs/numberofPairs;
  probAC = ACs/numberofPairs;
  probAT = ATs/numberofPairs;
  probAG = AGs/numberofPairs;
  probCA = CAs/numberofPairs;
  probCT = CTs/numberofPairs;
  probCG = CGs/numberofPairs;
  probCC = CCs/numberofPairs;
  probGA = GAs/numberofPairs;
  probGG = GGs/numberofPairs;
  probGT = GTs/numberofPairs;
  probGC = GCs/numberofPairs;
  probTT = TTs/numberofPairs;
  probTA = TAs/numberofPairs;
  probTC = TCs/numberofPairs;
  probTG = TGs/numberofPairs;
}
void findLetterProbability() // each letter probability math
{
  probA = numberOfA/numberOfChars;
  probT = numberOfT/numberOfChars;
  probG = numberOfG/numberOfChars;
  probC = numberOfC/numberOfChars;
}
void outputLines() // outputting all necessary lines
{
  string line;
  ofstream myfile ("JustinEwoldt.txt");

  myfile << "Justin Ewoldt" << endl;
  myfile << "2292364" << endl;
  myfile << "Sum: " << numberOfChars << endl;
  myfile << "Mean: " << linesMean << endl;
  myfile << "Variance: " << linesVariance << endl;
  myfile << "Standard Deviation: " << linesSD << endl;
  myfile << "Probability of A: " << probA << endl;
  myfile << "Probability of C: " << probC << endl;
  myfile << "Probability of T: " << probT << endl;
  myfile << "Probability of G: " << probG << endl;
  myfile << "Probability of AA: " << probAA << endl;
  myfile << "Probability of AC: " << probAC << endl;
  myfile << "Probability of AT: " << probAT << endl;
  myfile << "Probability of AG: " << probAG << endl;
  myfile << "Probability of CA: " << probCA << endl;
  myfile << "Probability of CC: " << probCC << endl;
  myfile << "Probability of CT: " << probCT << endl;
  myfile << "Probability of CG: " << probCG << endl;
  myfile << "Probability of TA: " << probTA << endl;
  myfile << "Probability of TC: " << probTC << endl;
  myfile << "Probability of TT: " << probTT << endl;
  myfile << "Probability of TG: " << probTG << endl;
  myfile << "Probability of GA: " << probGA << endl;
  myfile << "Probability of GC: " << probGC << endl;
  myfile << "Probability of GT: " << probGT << endl;
  myfile << "Probability of GG: " << probGG << endl;


  srand(time(NULL));
  double a, b, c, d;
  for(int i = 0; i != 1000; i++)
  {
    a = rand()/double(RAND_MAX);
    b = rand()/double(RAND_MAX);
    c = sqrt(-2 * log(a)) * cos(2*PI*b);
    d = (linesSD * c) + linesMean;
    if(int(d) == 9)
    {
      line = "AAAAAAAAA";
    }
    else if(int(d) == 10)
    {
      line = "AAAAAAAAAA";
    }
    else if(int(d) == 11)
    {
      line = "AAAAAAAAAAA";
    }
    else if(int(d) == 12)
    {
      line = "AAAAAAAAAAAA";
    }
    else
    {
      line = "AAAAAAAAAAAAA";
    }
    for(int i = 0; i < int(d); i++)
    {
      double random = rand()/double(RAND_MAX);
      if(random <= probA)
      {
        line[i] = 'A';
      }
      else if(random <= probC + probA && random > probA)
      {
        line[i] = 'C';
      }
      else if(random <= probG + probC + probA && random > probC + probA)
      {
        line[i] = 'G';
      }
      else
      {
        line[i] = 'T';
      }

    }
    myfile << line << endl;
  }
  myfile.close();

}
main(int argc, char** argv)
{
  string question;
  bool flow = true;
  while(flow)
  {
    fileStream(argv[1]); //parameter is the first command line argument
    calculateMean(numberOfLines, numberOfChars);
    calculateVariance(fileDestination);
    calculateSD(linesVariance);
    findPairs(fileDestination);
    findLetterProbability();
    findPairProbability();
    outputLines();
    cout << "Would you like to process another list?(Type yes or no): ";
    cin >> question;
    if(question != "yes")
    {
      flow = false;
    }
  }

  return 0;
}
