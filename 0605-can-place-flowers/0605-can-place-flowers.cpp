class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int pos = 0;
        int size = flowerbed.size();
        for(int i=0; i<size; i++){
            if (flowerbed[i] == 0) {
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        cout<<n<<endl;
        return n <= 0;
    }
};