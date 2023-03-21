class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        
        int count = 0;
        int l = flowerbed.size();
        
        
        if(l==1 && flowerbed[0]==0)
            return 1>=n;
            else if(l==1 && flowerbed[0]==1)
                return 0>=n;
        

        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            count++;
            flowerbed[0] = 1;
        }
        if (flowerbed[l - 1] == 0 && flowerbed[l - 2] == 0)
        {
            count++;
            flowerbed[l - 1] = 1;
        }

        for (int i = 1; i < l - 2; i++)
        {

            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                count++;
                flowerbed[i] = 1;
            }
        }

        return n <= count;
    }
};