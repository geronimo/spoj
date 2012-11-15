int calculate_envelop(bitset<4> bits, vector< vector<int> > rec){
    int result = 0;
    for(int i=0; i<rec.size()-1; i++){
        if(bits[i]){
            result += rec[i][0];
            if(bits[i+1]){
                result += _abs(rec[i+1][1] - rec[i][1]);
            } else {
                result += _abs(rec[i+1][0] - rec[i][1]);
            } 
        } else {
            result += rec[i][1];
            if(bits[i+1]){
                result += _abs(rec[i+1][1] - rec[i][0]);
            } else {
                result += _abs(rec[i+1][0] - rec[i][0]);
            } 
        }
    }
    if(bits[rec.size()-1]){
        result += rec[rec.size()-1][0];
    } else {
        result += rec[rec.size()-1][1];
    }
    return result;
}

int brute_force(vector< vector<int> > rec){
    int response = 0;
    for(int mask = 0; mask < pow(2, rec.size()); mask++){
        bitset<4> bits(mask);
        int result = calculate_envelop(bits, rec);
        //cout << bits << " " << result << endl;
        if(result > response){
            response = result;
        }
    }
    return response;
}


