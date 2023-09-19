#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include <stdio.h>
#include <string>

int KeresesEgySzallal(std::string word, std::string sentence)
{
    for (int i = 0; i < sentence.length(); ++i)
    {
        int j = 0;
        while (j < word.length() && sentence[i+j] == word[j])
        {
            j++;
        }
        if (j == word.length())
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::string word = "abc";
    std::string sentence = "ababcx";
    
    int res = KeresesEgySzallal(word, sentence);

    printf(std::to_string(res).c_str());
}
