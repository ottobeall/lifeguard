#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


int totalDuration(std::vector<std::vector<int>> input){
    int min = input[0][0];
    int max = input[0][1];
    for(std::vector<int> i : input){
        if (i[0] < min){
            min = i[0];
        }
        if (i[1] > max){
            max = i[1];
        }
    }
    bool bits[max-min] = {false};
    for(int i = 0; i < input.size(); i++){
        for (int j = input[i][0]; j < input[i][1]; j++){
            bits[j-min] = true;
        }
    }
    int length = 0;
    for(bool i : bits){
        if(i){
            length++;
        }
    }
    return length;
}


int main(){
    std::ifstream fin("lifeguards.in");
    std::ofstream fout("lifeguards.out");
    int n;
    fin >> n;
    std::vector<std::vector<int>> lifeguards;
    std::cout << n << "\n";
    for(int i = 0; i < n; i++){
        int beginning;
        int end;
        fin >> beginning;
        fin >> end;
        lifeguards.push_back({beginning, end});
    }
    for(std::vector<int> j : lifeguards){
        std::cout << j[0] << " " << j[1] << "\n";
    }
    
    std::cout << totalDuration(lifeguards) << "\n";
    int maxLength = 0;
    for(int i = 0; i < lifeguards.size(); i++){
        std::vector<std::vector<int>> smallerTeam = lifeguards;
        smallerTeam.erase(smallerTeam.begin()+i);
        if(totalDuration(smallerTeam) > maxLength){
            maxLength = totalDuration(smallerTeam);
        }
    }
    fout << maxLength;
    std::cout << "Max Length: " << maxLength;
    
    return 0;
}
