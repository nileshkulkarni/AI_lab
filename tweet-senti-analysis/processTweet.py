import re

#process tweets
def processTweet(tweet):
    #start processing
    #convert tweet to lower case
    tweet=tweet.lower()
    #Convert www.* or https?://* to URL
    tweet = re.sub('((www\.[\s]+)|(https?://[^\s]+))','URL',tweet)
    #Convert @username to AT_USER
    tweet = re.sub('@[^\s]+','AT_USER',tweet)
    #Remove additional white spaces
    tweet = re.sub('[\s]+', ' ', tweet)
    #Remove hastag '#'
    tweet = re.sub(r'#([^\s]+)', r'\1', tweet)
    #trim
    tweet = tweet.strip('\'"')
    return tweet

#process the entire tweetfile
def processFile(filename):
    #Read the tweets one by one and process it
    read = 'TweetsCorpus/twitter_'+filename
    write='TweetsCorpus/processed_'+filename
    fr = open(read, 'r')
    fw = open(write,'a')
    line = fr.readline()
     
    while line:
        split_tweet = line.split('\t')
        processedTweet = processTweet(split_tweet[1])
        fw.write(split_tweet[0])
        fw.write('\t')
        fw.write(processedTweet)
        fw.write('\n')
        line = fr.readline()
        
    #end loop
    fr.close()
    fw.close()



            
