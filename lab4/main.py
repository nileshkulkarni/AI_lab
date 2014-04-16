from optparse import OptionParser
from processTweet import *
import os
def clean():
    filelist = [ f for f in os.listdir("TweetsCorpus/newCorpus") if f.startswith("processed_") ]
    for f in filelist:
        os.remove("TweetsCorpus/newCorpus/"+f)

if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option("-a","--all", action="store_true", dest="all", default=None, help="Run the entire script")
    parser.add_option("-p", "--preprocess", action="store_true", dest="preprocess", default=None, help="Process most recent data")
    parser.add_option("-e", "--extract", action="store_true", dest="extractfeature", default=None, help="Extract Feature Vector")
    parser.add_option("-d", "--clean", action="store_true", dest="clean", default=None, help="Clean previous processed files")
    parser.add_option("-o", "--onetweet", action="store_true", dest="one_tweet", default=None, help="Classify a single tweet")
    (options, args) = parser.parse_args()

    if options.all:
        options.preprocess = options.extractfeature =  options.classify = True

    if options.one_tweet:
        options.extractfeature =  options.classify = True

    if options.preprocess:
        print "Preprocessing sample tweets" 
        clean()
        print "Processing negative tweets..."
        processFile("negative")
        print "Processing positive tweets..."
        processFile("positive")
        print "Processing objective tweets..."
        processFile("objective")
    
    if options.extractfeature:
        print "Extracting Feature Vector"
        featureVector = []
        print "Extracting positive features"
        getAllFeatureWords("positive",featureVector)
        print "Extracting negative features" 
        getAllFeatureWords("negative",featureVector)
        print "Extracting objective features"
        getAllFeatureWords("objective",featureVector)
        print "Finding the word frequency"
        worddict = {}
        worddict = getFreq(featureVector)
        print "Processed word universe according to frequency, now writing to file"
        finallist = []
        finallist = finalVector(worddict)
        print "Wrote word universe, now extracting feature vector"
        printFeatureVector(finallist)
        print "Done extracting features and writing to file"

    if options.classify:
		print "Classifying a tweet ..."
		one_tweet(finallist)
		print "...Extracted feature vector, run the training"
        
    if options.clean:
        print "Cleaning crap..."
        clean()
        print "....Done cleaning"




