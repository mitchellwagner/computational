# fill empty cells with 0
dat <- read.table("oil.txt", header=TRUE, fill=TRUE)

# mileage between oil changes
pdf("mileage.pdf")
hist(dat$dm, breaks=seq(2000,9000,400),
     border="red",
     col="yellow",
     las=1, # rotate y label by 90 degree
     main="", # histogram title
     xlab="mileage between recorded oil changes [mile]",
     ylab="times of recorded oil changes")

# daily mileage
h<-hist(dat$daily, breaks=seq(0,200,20),
	border="red",
	col="yellow",
	las=1, # rotate y label by 90 degree
	main="", # histogram title
	xlab="daily mileage [mile]",
	ylab="number of records",
	#prob=T, # normalize histogram
	)
# x of fitting function
min=min(dat$daily)
max=max(dat$daily)
xfit<-seq(min, max, length=800)

# y of normalized fitting function
m<-mean(dat$daily)
s<-sqrt(var(dat$daily))
yfit<-dnorm(xfit, mean=m, sd=s)

# scale y
d<-h$density
c<-h$counts
yfit<-yfit*c/d

# plot fitting function
lines(xfit, yfit, col="blue", lwd=2)
legend(110,12,bty="n",sprintf("mean: %.1f mile",m))
