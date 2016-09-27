dat <- scan("cost.dat")
lbl <- c("Oil", "Fuel", "Insurance", "Car", "Service")
pct <- round(dat/sum(dat)*100)
lbl <- paste(lbl, pct) # add percents to labels
lbl <- paste(lbl,"%",sep="") # add % to labels
pdf("cost.pdf")
pie(dat, labels=lbl, main=sprintf("Total: $%.0f",sum(dat)))
barplot(dat, names.arg=lbl, las=1, ylab="cost [$]", main=sprintf("Total: $%.0f",sum(dat)))
