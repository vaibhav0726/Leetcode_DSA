class SnapshotArray {
public:
    int sid;
    vector<map<int, int>> mp;
    SnapshotArray(int length) {
        sid = 0;
        mp.resize(length);
        for(int i=0;i<length;i++){
            mp[i][0]=0;
        }
    }
    
    void set(int index, int val) {
        mp[index][sid] = val;
    }
    
    int snap() {
        sid++;
        return sid-1;
    }
    
    int get(int index, int snap_id) {
        if(mp[index].find(snap_id)==mp[index].end()){
            auto it= --mp[index].lower_bound(snap_id);
            return it->second;
        }
        return mp[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */