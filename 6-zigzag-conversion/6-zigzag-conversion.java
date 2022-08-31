class Solution {
    public String convert(String s, int numRows) 
    {
        if(numRows==1)
            return s;
        String res = "";
        String[][] arr = new String[numRows][s.length()];
        int i=0;
        int j=0;
        while(j!=s.length())
        {
            for(int x=0; x<numRows && j<s.length(); x++)
            {
                arr[x][i]=String.valueOf(s.charAt(j));
                // System.out.println(x+" "+i+" "+arr[x][i] +" "+j);
                j++;
            }
            i++;
            for(int y=numRows-2; y>0 && j<s.length(); y--)
            {
                arr[y][i]=String.valueOf(s.charAt(j));
                // System.out.println(y+" "+i+" "+arr[y][i]+" "+ j);
                j++;
            }
            i++;
        }
        for(i=0; i<arr.length; i++){
            for(j=0; j<arr[0].length; j++){
                if(arr[i][j]!=null){
                    res+=arr[i][j];
                }
            }
        }
        
        // for(int a=0; a<arr.length; a++)
        // {
        //     for(int b=0; b<arr[0].length; b++)
        //     {
        //         System.out.print(arr[a][b]+" ");
        //     }
        //     System.out.println();
        // }
        
        return res;
    }
}