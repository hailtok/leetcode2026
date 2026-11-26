// Problem 1352: Product of the Last K Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
    vector<int>prefix{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            prefix={1};
        }
        else{
            prefix.push_back(prefix.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k>=prefix.size()){
            return 0;
        }
        return prefix[prefix.size()-1]/prefix[prefix.size()-1-k];
    }
};