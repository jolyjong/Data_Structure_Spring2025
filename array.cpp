#include <iostream>
using namespace std;

static const int ROWS = 4;
static const int COLS = 5;

void countFreq(const unsigned char arr[ROWS][COLS])
{

    int freq[256] = {0};

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            freq[arr[i][j]]++;
        }
    }

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            char c = i;  
            cout << "The Character '" << c << "' is repeated " << freq[i] << " time(s).\n";
        }
    }
}

//testing
int main()
{
    unsigned char arr[ROWS][COLS] = 
    {
        {'A','B','C','D','E'},
        {'F','G','H','H','I'},
        {'J','K','K','L','M'},
        {'A','B','C','D','E'}
    };

    countFreq(arr);

    return 0;
}
