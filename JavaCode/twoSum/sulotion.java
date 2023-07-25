
import java.util.HashMap;

public class sulotion{
    public static void main(String[] args) {
        int[] nums1 = {2, 7, 11, 15};
        sulotion twosum = new sulotion();
        int[] output = twosum.twoSum(nums1, 9);
        System.out.println("[" + output[0] + ", " + output[1] + "]");
    }
    
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        //边添加map，边查找
        for(int i = 0; i < nums.length; i++){
            if(map.containsKey(target - nums[i])){
                return new int[] {map.get(target - nums[i]), i};
            }
            map.put(nums[i], i);
        }    

        //找不到的情况抛出异常提示语句
        throw new IllegalArgumentException("error : no answer!");
    }
}