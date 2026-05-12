import java.util.Arrays;

class Solution {
    public int minimumEffort(int[][] tasks) {
        // Step 1: Sort tasks based on the difference (minimum - actual) in descending order.
        // This ensures we tackle tasks that leave us with the most residual energy first.
        Arrays.sort(tasks, (a, b) -> (b[1] - b[0]) - (a[1] - a[0]));
        
        int totalEnergyNeeded = 0;
        int currentEnergy = 0;
         
        // Step 2: Traverse through the sorted tasks
        for (int[] task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            
            // If our current energy is less than what's required to even start the task
            if (currentEnergy < minimum) {
                // Add the deficit to our initial starting energy
                totalEnergyNeeded += (minimum - currentEnergy);
                // Now our current energy meets the minimum requirement
                currentEnergy = minimum; 
            }
            
            // Complete the task and deduct the actual energy spent
            currentEnergy -= actual;
        }
        
        return totalEnergyNeeded;
    }
}
