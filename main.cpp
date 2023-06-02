#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //Variables
    int Opt = 0;
    
    const int OptionA = 1;
    const int OptionB = 2;
    
    int A_BatLvl = 0;
    
    double B_STMrk = 0;
    double B_STTtlMrk = 0;
    double B_PercST = 0;
    
    //Error Variables
    const int SUCCESS = 1;
    const int ERR_CONV = -1;
    const int ERR_RANGE = -2;
    
    //Select option
    cout << "Do you want to choose Option 1 (battery) or Option 2 (Semester Test)? " << endl;
    cin >> Opt;
    
    //Validate choice
    if (cin.fail())
    {
        cerr << "Could not convert string to integer.";
        exit(ERR_CONV);
    }
    
    if(Opt < 1 || Opt > 2)
    {
        cerr << "Number not between 1 and 2" << endl;
        exit(ERR_RANGE);
    }
    
    switch(Opt)
    {
        case OptionA:
        {
            //Option A
            
            cout << "Please input the remaining battery level. (0 - 100) " << endl;
            cin >> A_BatLvl;
            
            if (cin.fail())
            {
                cerr << "Could not convert string to integer.";
                exit(ERR_CONV);
            }
            
            if(A_BatLvl >= 0 && A_BatLvl <= 15 )
            {
                cout << "Charging required! You may get stuck on the road!" << endl;
            }
            else if (A_BatLvl > 15 && A_BatLvl <= 35)
            {
                cout << "Barely enough power remaining. Use the shortest route." << endl;
            }
            else if (A_BatLvl > 35 && A_BatLvl <= 75)
            {
                cout << "There should be enough power to last you the entire trip." << endl;
            }
            else if (A_BatLvl > 75 && A_BatLvl <= 100)
            {
                cout << "The battery is sufficiently charged. Happy driving." << endl;
            }
            
            break;
        }
        
        case OptionB:
        {
            //Option B
            
            cout << "Please enter your semester test mark." << endl;
            cin >> B_STMrk;
            
            if (cin.fail())
            {
                cerr << "Could not convert string to integer.";
                exit(ERR_CONV);
            }
            cout << "Please enter the total possible marks for the semester test" << endl;
            cin >> B_STTtlMrk;
            
            if (cin.fail())
            {
                cerr << "Could not convert string to integer.";
                exit(ERR_CONV);
            }
            
            B_PercST = B_STMrk / B_STTtlMrk *100;
            cout << "The percentage is: " << B_PercST << endl;
            
            if(B_PercST > 100 || B_PercST < 0)
            {
                cerr << "The Percentage is not between 0 and 100" << endl;
                exit(ERR_RANGE);
            }
            
            cout << (B_PercST < 50 ? "You need to invest more in your schoolwork":"Keep it up.") << endl;
            
            break;
            }
            
        default:
        {
            cerr << "The status operator probably did not update." << endl;
            exit(0);
        }
        exit(SUCCESS);
    }
  
  return 0;
  
}