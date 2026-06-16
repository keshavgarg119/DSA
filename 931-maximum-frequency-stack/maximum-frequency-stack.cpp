class FreqStack {
public:

    unordered_map<int,int>freq;
    unordered_map<int, stack<int>> group; // freq i-> {stack}

    int maxFreq = 0;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;

        int f = freq[val];

        maxFreq = max(f, maxFreq);

        group[f].push(val);
    }
    
    int pop() {
        int value = group[maxFreq].top();
        group[maxFreq].pop();

        freq[value]--;

        if(group[maxFreq].empty()) {
            maxFreq--;
        }

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */