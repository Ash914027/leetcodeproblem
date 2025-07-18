
class Solution {
    public long minimumDifference(int[] nums) {
        // \U0001f4cf First, let's figure out how many friends (numbers) are in each team.
        int n = nums.length / 3;  //  'n' is the size of each team (subarray)

        // \U0001fad8 Left Side:  Building the first team and keeping track of their scores (sums)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder()); // Team 1 (max-heap for smallest sums), using a max-heap to store smallest numbers
        long[] sumLeft = new long[n + 1]; // Array to store team scores
        long currSum = 0; // Current total score for Team 1

        // Loop to form the first team
        for (int i = 0; i < n; i++) { //  Go through the first 'n' numbers, adding each number to form the first team
            maxHeap.add(nums[i]); // Add the number to our priority queue (heap) - think of this like adding players to your team
            currSum += nums[i];  // Add it to the team's running score
        }
        sumLeft[0] = currSum; // Initialize sumLeft, like setting the initial team score

        // \U0001f4a5 Loop to update the team scores as we add more friends/numbers
        for (int i = n; i < 2 * n; i++) {  // For the next 'n' numbers, like new players coming to the team
            if (nums[i] < maxHeap.peek()) {  // If this new player (number) has a lower score than the worst player on the team
                currSum -= maxHeap.poll();     // Remove the worst player from the team
                maxHeap.add(nums[i]);          // Add the new, better player
                currSum += nums[i];          // Update team score
            }
            sumLeft[i - n + 1] = currSum;       // Save the team score for the current window
        }

        // \U0001f46f Right Side:  Building the second team
        PriorityQueue<Integer> rightMinHeap = new PriorityQueue<>(); // Team 2 (min-heap for largest sums)
        long[] sumRight = new long[n + 1]; // Array to store team scores
        long currentSumRight = 0; // Current total score for Team 2

        // Loop to build the second team
        for (int i = 2 * n; i < 3 * n; i++) {  //  Go through the last 'n' numbers, adding each number to form the second team
            rightMinHeap.add(nums[i]);  // Add the number to our priority queue (heap)
            currentSumRight += nums[i];   // Add the player's score to the team's running score
        }
        sumRight[0] = currentSumRight;   // Initialize the team's score

        // \U0001f504 Loop to update the team scores
        for (int i = 2 * n - 1; i >= n; i--) {   // For the numbers in the middle, we will add them, replacing the weakest (smallest value)
            if (nums[i] > rightMinHeap.peek()) {   // If this new player is better than the worst player of Team 2
                currentSumRight -= rightMinHeap.poll();  // Remove the worst from the team
                rightMinHeap.add(nums[i]);      // Add the new player
                currentSumRight += nums[i];  // Update the team's score
            }
            sumRight[2 * n - i] = currentSumRight;  // Save the team score
        }

        // \U0001f3c6 Find the Best Split!
        long minDifference = Long.MAX_VALUE; // Initialize the minimum difference to the highest possible value

        for (int i = 0; i <= n; i++) {
            minDifference = Math.min(minDifference, sumLeft[i] - sumRight[n - i]); // Find the minimum difference between the teams' scores
        }

        return minDifference;  // Return the lowest difference - the best team split!
    }
}