from optparse import OptionParser
from processTweet import *
import os
def clean():
    filelist = [ f for f in os.listdir("TweetsCorpus") if f.startswith("processed_") ]
    for f in filelist:
        os.remove("TweetsCorpus/"+f)

if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option("-a","--all", action="store_true", dest="all", default=None, help="Run the entire script")
    parser.add_option("-p", "--preprocess", action="store_true", dest="preprocess", default=None, help="Process most recent data")
    parser.add_option("-d", "--clean", action="store_true", dest="clean", default=None, help="Clean previous processed files")
    (options, args) = parser.parse_args()

    if options.all:
        options.preprocess = options.combine = True

    if options.preprocess:
        print "Preprocessing sample tweets" 
        clean()
        print "Processing negative tweets..."
        processFile("negative")
        print "Processing positive tweets..."
        processFile("positive")
        print "Processing objective tweets..."
        processFile("objective")

    if options.clean:
        print "Cleaning crap..."
        clean()
        print "....Done cleaning"



