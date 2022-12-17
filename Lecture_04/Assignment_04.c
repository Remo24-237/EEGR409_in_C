/*This a program written to read data from three different data files (TruePos.txt, 
    FalseNeg.txt, and FalsePos.txt) then calculate the DSC values using the data from each file
    then store in a separate file (results.csv). The output data will then be used to plot
    a graph

    @author
    Remo24
    EEGR409
    Assignment 04


*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

#define INPUT_FILE_1 "TruePos.txt"
#define INPUT_FILE_2 "FalsePos.txt"
#define INPUT_FILE_3 "FalseNeg.txt"
#define OUTPUT_FILE "results.csv"


int main(){

    FILE *infile_1, *infile_2, *infile_3, *outfile;
    int tp, fp, fn, num_records=0;
    float dsc=0, dsc_1=0, min_dsc=0, max_dsc=0,average_dsc=0,dsc_sum=0;

   /* opening input and output files */
    infile_1= fopen(INPUT_FILE_1,"r");
    infile_2= fopen(INPUT_FILE_2, "r");
    infile_3= fopen(INPUT_FILE_3, "r");
    outfile= fopen(OUTPUT_FILE,"w");

    /* Checking if there file was opened successfully */
    if(infile_1==NULL || infile_2==NULL || infile_3==NULL){
        printf("\n One of the input files failed to open!");
    }else
    {
        printf("\n All input files opened successfully!");
        fprintf(outfile," TP,FP, FN, DSC \n");
        /* the loop will check the files only if they all have content */
        while((!(feof(infile_1))) && (!(feof(infile_2))) && (!(feof(infile_3))))
        {
            fscanf(infile_1, "%d", &tp);
            fscanf(infile_2, "%d", &fp);
            fscanf(infile_3, "%d", &fn);
            
            dsc_1 = (2*tp)+(fp+fn) ;/* storing temporary value from calculation of dsc */
            dsc =((2*tp)/dsc_1)*100;
            dsc_sum +=dsc;
            num_records++;
            fprintf(outfile, " %d,%d,%d, %.4f \n", tp, fp, fn, dsc);
            
            
            if(dsc>max_dsc){
                max_dsc=dsc;
            }
           
        }
        
        average_dsc=(dsc_sum/num_records);
        fprintf(outfile,"-------------------------------------\n");
        fprintf(outfile,"The number of data points is %d.\n",num_records);
        fprintf(outfile,"The average DSC value is %.4f\n",average_dsc);
        fprintf(outfile,"The maximum DSC is %.4f \n", max_dsc);
        
    }
    /* closing all files in use*/
    fclose(infile_1);
    fclose(infile_2);
    fclose(infile_3);
    fclose(outfile);

    return 0;
}
