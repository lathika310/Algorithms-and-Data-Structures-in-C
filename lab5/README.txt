In order to accomadate standalone tags, 
I would not require a start tag (as I currently do),
instead of giving the invalid XML error and stoping the algorithm,
and I would just not attempt to push it to the stack at all. 

Part 1 Bugs:
-Does not give an invalid xml error when start tag does not match end tag

reinstantionate temp w/mlloc
copy tag to temp, only push after that. 
