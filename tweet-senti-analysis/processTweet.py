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
    tweet = re.sub(r"(.)\1{1,}",r'\1\1',tweet)
    return tweet

#process the entire tweetfile
def processFile(filename):
    #Read the tweets one by one and process it
    read = 'TweetsCorpus/twitter_'+filename
    write= 'TweetsCorpus/processed_'+filename
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



            
#start getStopWordList
def getStopWordList(stopWordListFileName):
    #read the stopwords file and build a list
    stopWords = []
    stopWords.append('AT_USER')
    stopWords.append('URL')

    fp = open(stopWordListFileName, 'r')
    line = fp.readline()
    while line:
        word = line.strip()
        stopWords.append(word)
        line = fp.readline()
    fp.close()
    return stopWords
#end


#start getfeatureVector from tweets
def getFeatureVector(tweet,featureVector,stopWords):
    #split tweet into words
    words = tweet.split()
    for w in words[1:]:
        #strip punctuation
        w = w.strip('\'"?,.!')
        #check if the word stats with an alphabet
        val = re.search(r"^[a-zA-Z][a-zA-Z0-9]*$", w)
        #ignore if it is a stop word
        if(w.lower() in stopWords or val is None):
            continue
        else:
            if(w.lower() not in featureVector):
                featureVector.append(w.lower())
    return featureVector
#end

#start getAllFeatureWords from preprocessed tweets
def getAllFeatureWords(filename,featureVector):
    filename = 'TweetsCorpus/processed_'+filename
    stopWords = getStopWordList("TweetsCorpus/stopword.txt")
    fp = open(filename,'r')
    line = fp.readline()
    while line:
        getFeatureVector(line,featureVector,stopWords)
        line = fp.readline()
    return
#end

#start printFeature vector
def printFeature(featureVector):
    fp = open("TweetsCorpus/featureVector.dump",'w')
    for word in featureVector:
        fp.write(word)
        fp.write('\n')
    return
#end
