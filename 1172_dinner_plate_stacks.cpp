// Problem 1172: Dinner Plate Stacks
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/dinner-plate-stacks/

class DinnerPlates {
private:
    int size;
    vector<stack<int>>stacks;
    set<int>available;
public:
    DinnerPlates(int capacity) {
        size=capacity;
    }
    void push(int val) {
        while (!available.empty()&&*available.begin()>=stacks.size()){
            available.erase(available.begin());
        }
        if (available.empty()) {
            stacks.push_back(stack<int>());
            int i =stacks.size()-1;
            stacks[i].push(val);
            if (stacks[i].size()<size){
                available.insert(i);
            }
        } 
        else {
            int i=*available.begin();
            stacks[i].push(val);
            if (stacks[i].size()==size){
                available.erase(available.begin());
            }
        }
    }
    int pop() {
        while(!stacks.empty()&&stacks.back().empty()){
            int last=stacks.size()-1;
            available.erase(last);
            stacks.pop_back();
        }
        if(stacks.empty()){
            return -1;
        }
        int i=stacks.size()-1;
        int temp=stacks[i].top();
        stacks[i].pop();
        available.insert(i);
        while (!stacks.empty()&&stacks.back().empty()) {
            int last=stacks.size()-1;
            available.erase(last);
            stacks.pop_back();
        }
        return temp;
    }
    
    int popAtStack(int index) {
        if(index>=stacks.size()||stacks[index].empty()) {
            return -1;
        }
        int temp=stacks[index].top();
        stacks[index].pop();
        available.insert(index);
        while (!stacks.empty()&&stacks.back().empty()) {
            int last=stacks.size()-1;
            available.erase(last);
            stacks.pop_back();
        }
        return temp;
    }
};