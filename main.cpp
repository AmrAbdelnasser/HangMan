#include <bits/stdc++.h>

//By: Amr Abdelnasser
//amr.adelnasr@gmail.com
//May 22, 2019
//02:11 PM (PT)

using namespace std;

void printhang(int counter)
{
    if (counter==1)
        cout<<" _________      "<<'\n';
    else if (counter ==2)
    {
        cout<<" _________      "<<'\n';
        cout<<"|         |     "<<'\n';
    }
    else if (counter == 3)
    {
        cout<<" _________      "<<'\n';
        cout<<"|         |     "<<'\n';
        cout<<"|         o     "<<'\n';
    }
    else if (counter ==4)
    {
        cout<<" _________      "<<'\n';
        cout<<"|         |     "<<'\n';
        cout<<"|         o     "<<'\n';
        cout<<"|        /|\\   "<<'\n';
    }
    else if (counter ==5)
    {
        cout<<" _________      "<<'\n';
        cout<<"|         |     "<<'\n';
        cout<<"|         o     "<<'\n';
        cout<<"|        /|\\   "<<'\n';
        cout<<"|        / \\   "<<'\n';
    }
    else if (counter ==6)
    {
        cout<<" _________      "<<'\n';
        cout<<"|         |     "<<'\n';
        cout<<"|         o     "<<'\n';
        cout<<"|        /|\\   "<<'\n';
        cout<<"|        / \\   "<<'\n';
        cout<<"|               "<<'\n';
        cout<<"   Game Over!!  "<<endl;
    }
}

int main()
{
    ifstream inFile;
    inFile.open("words.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string x;
    vector<string> y; //vector to hold all the words
    while (inFile >> x) {
        y.push_back(x);
    }
    srand(time(0));  // Initialize random number generator.
    int r = (rand() % y.size()); //random index between 0 and the size of y
    string word_to_guess = y[r];
    cout<<word_to_guess<<endl; //for testing purposes only (shouldn't be displayed in the real game)
    string word_to_display; //the dashes to be filled with letters
    for (int i=0; i<word_to_guess.size(); ++i)
    {
        word_to_display+="-";
        cout<<word_to_display[i];
    }
    cout<<endl;
    char z;
    int counter =0; //to count the number of wrong guesses
    int counterright = 0; //to check if the game is completed successfully
    size_t found;
    //start guessing letters
    while (counter <6)
    {
        cout<<"Enter a letter: ";
        cin>>z;
        found = word_to_guess.find(z);
        if (found!=string::npos) //correct guess
        {
            word_to_display[found] = word_to_guess[found];
            word_to_guess.replace(found,1,"-"); //to prevent a user from re-entering the same letter again
            for (int i=0; i<word_to_guess.size(); ++i)
            {
                cout<<word_to_display[i];
            }
            cout<<endl;
            counterright++;
            if(counterright == word_to_guess.size())
            {
                cout<<"Congratulations !"<<endl;
                break;
            }
        }
        else //wrong guess
        {
            cout<<"Wrong Guess"<<'\n';
            counter++;
            printhang(counter);
        }
        //if(counter == 6)


    }
    inFile.close();
    return 0;
}
