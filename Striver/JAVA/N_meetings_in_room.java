// Given one meeting room and N meetings represented by two arrays, start and end,
// where start[i] represents the start time of the ith meeting and end[i]
// represents the end time of the ith meeting, determine the maximum number of meetings
// that can be accommodated in the meeting room if only one meeting can be held at a time.

// Look For Reference In the Book-3 On Pg No 14-15


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class N_meetings_in_room{
    public static class Pair{
        int first;
        int second;
        Pair(int a, int b){
            first = a;
            second = b;
        }
    }
    public static int N_meeting(int[] start, int [] end){
        int n = start.length;
        if(n==0)    return 0;
        List<Pair> meetings = new ArrayList<>();
        for(int i=0;i<n;i++){
            meetings.add(new Pair(start[i], end[i]));
        }
        Collections.sort(meetings, (a,b)->Integer.compare(a.second, b.second));
        int cnt = 1;
        int lastEnd = meetings.get(0).second;
        for(int i=1;i<n;i++){
            if(meetings.get(i).first>=lastEnd){
                lastEnd = meetings.get(i).second;
                cnt++;
            }
        }
        return cnt;
    }
    public static void main(String[] args) {
        int[] start = {1, 3, 0, 5, 8, 5};
        int[] end = {2, 4, 6, 7, 9, 9};
        int N_meet = N_meeting(start, end);
        System.out.println("Number Of Meetings Possible : " + N_meet);
    }
}