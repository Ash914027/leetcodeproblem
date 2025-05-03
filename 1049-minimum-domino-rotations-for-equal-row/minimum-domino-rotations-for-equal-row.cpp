class Solution 
{
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        // Step 1: Try making all values equal to tops[0]
        int result = check(tops[0], tops, bottoms);

        // Step 2: If it's possible, return the result
        if (result != -1)
        {
            return result;
        } 

        // Step 3: Otherwise, try bottoms[0]
        return check(bottoms[0], tops, bottoms);
    }

private:
    // Step 4: Helper function to count required rotations
    int check(int target, vector<int>& tops, vector<int>& bottoms) 
    {
        int rotateTop = 0;     // Rotations to bring target to top
        int rotateBottom = 0;  // Rotations to bring target to bottom

        // Step 5: Loop through all dominoes
        for (int i = 0; i < tops.size(); ++i) 
        {
            // Step 6: If target is not present on either side, it's impossible
            if (tops[i] != target && bottoms[i] != target) 
            {
                return -1;
            }

            // Step 7: Count how many times we must rotate to top
            if (tops[i] != target)
            {
                rotateTop++;
            } 

            // Step 8: Count how many times we must rotate to bottom
            if (bottoms[i] != target)
            {
                rotateBottom++;
            } 
        }

        // Step 9: Return the minimum number of rotations needed
        return min(rotateTop, rotateBottom);
    }
};