import java.text.SimpleDateFormat;
import java.util.Calendar;

/*
*
*  CovidPredictor based on statistics. Based on India only -/
*
 */

public class CovidPredictor {
    public static void main(String[] args) {
        String firstCase = "2020-03-04";
        int numberOfCases = 15;
        double rate = 1.15;
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Calendar c = Calendar.getInstance();
        try{
            c.setTime(simpleDateFormat.parse(firstCase));
        } catch (Exception e){
            e.printStackTrace();
        }
        SimpleDateFormat simpleDateFormat1 = new SimpleDateFormat("d MMM yyyy");
        // Calculation:
        // E is a constant factor and p is probability that virus gets transfer
        // nextDay = (1 + E*p) * today
        //
        for(int i = 2; i <= 108; i++){
            c.add(Calendar.DAY_OF_MONTH, 1);
            if (i % 10 == 0) {
                System.out.println("Date : " + simpleDateFormat1.format(c.getTime()) + " Cases: " + numberOfCases);
                if (i <= 20) {
                    numberOfCases *= 0.7; // before summer cases
                } else {
                    numberOfCases *= 0.6; // summer recovery cases
                }
            }
            if (i % 15 == 0) {
                rate -= 0.01; // every 15 days if rate decrease because of various reasons
            }
            numberOfCases *= rate;
        }
    }
}
