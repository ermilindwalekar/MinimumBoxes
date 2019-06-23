#include <iostream>
#include <map>

#define SMALL 2
#define MEDIUM 3
#define LARGE 5

int boxOfSpecificSize(int item, int capacity){
   int boxes = item / capacity;
   if(item % capacity != 0)
    boxes++;

   return boxes;
}

void findMinimalBoxes(int item, map<char, int>& solution){

    //Handle when no items are left to be placed
    if(item == 0)
        return;

    //If just 1 item is left to place
    if(item == 1){
        if(solution.insert({'S', 1}).second == false){
            map<char, int>::iterator it = solution.find('S');
            ++it->second;
        }
        return;
    }

    if(item >= LARGE){
        solution.insert({'L', item/LARGE});
        //Recursively call the function with left over items to place
        findMinimalBoxes(item % LARGE, solution);
        return;
    }

    if(item >= MEDIUM){
        solution.insert({'M', item/MEDIUM});
        findMinimalBoxes(item % MEDIUM, solution);
        return;
    }

    if(item >= SMALL){
        solution.insert({'S', item/SMALL});
        findMinimalBoxes(item % SMALL, solution);
    }
}

int main()
{
    //Storing type of box and quantity required
    map<char,int> solution;
    map<char,int>::iterator it;

    findMinimalBoxes(37, solution);

    for(it = solution.begin(); it != solution.end(); it++){
        cout<< it->first << " " << it->second<<endl;
    }
    return 0;
}
