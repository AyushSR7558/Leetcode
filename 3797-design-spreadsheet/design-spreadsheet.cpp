class Spreadsheet {
private:
    unordered_map<string, int> virtualCell;

    bool check(string x) {
        int n = x.size();
        for(int i = 0; i < n; i++) {
            if(!(x[i] >= '0' && x[i] <= '9')) return false;
        }
        return true;
    }
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        virtualCell[cell] = value;
    }
    
    void resetCell(string cell) {
        virtualCell[cell] = 0;
    }
    
    int getValue(string formula) {
        string temp = formula;
        int val1 = 0, val2 = 0;
        temp = temp.substr(1);

        size_t pos = temp.find('+');
        string A = temp.substr(0,pos);
        string B = temp.substr(pos + 1);

        if(check(A)) {
            val1 = stoi(A);
        }else {
            val1 = virtualCell[A];
        }
        if(check(B)) {
            val2 = stoi(B);
        }else {
            val2 = virtualCell[B];
        }
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */