
Get the Data with Pandas

When the Titanic sank, 1502 of the 2224 passengers and crew were killed. One of the main reasons for this high level of casualties was the lack of lifeboats on this self-proclaimed "unsinkable" ship.

Those that have seen the movie know that some individuals were more likely to survive the sinking (lucky Rose) than others (poor Jack). In this course, you will learn how to apply machine learning techniques to predict a passenger's chance of surviving using Python.

Let's start with loading in the training and testing set into your Python environment. You will use the training set to build your model, and the test set to validate it. The data is stored on the web as csv files; their URLs are already available as character strings in the sample code. You can load this data with the read_csv() method from the Pandas library.


training data - train.csv
testing data - test.csv

Use Pandas library
export PATH=~/anaconda2/bin:$PATH
- to read the csv 
