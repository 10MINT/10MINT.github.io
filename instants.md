---
layout: content
---
# All About Instants
#### (At least I hope it's all)
## What are instants?
Instants are the way Android represents time. Lets take a look what an instant outputs
```java
java.util.GregorianCalendar[time=1583593327482,areFieldsSet=true,lenient=true,zone=Europe/Berlin,
firstDayOfWeek=2,minimalDaysInFirstWeek=4,ERA=1,YEAR=2020,MONTH=2,WEEK_OF_YEAR=10,WEEK_OF_MONTH=2,
DAY_OF_MONTH=7,DAY_OF_YEAR=67,DAY_OF_WEEK=7,DAY_OF_WEEK_IN_MONTH=1,AM_PM=1,HOUR=4,HOUR_OF_DAY=16,
MINUTE=2,SECOND=7,MILLISECOND=482,ZONE_OFFSET=3600000,DST_OFFSET=0]
```

As you can see, every piece of information is hidden in here. That is also the reason you cannot just output the instant, instead you have to use a converted versions, e.g. [FormatDate](http://ai2.appinventor.mit.edu/reference/components/sensors.html#Clock.FormatDate){:target="_blank"} as a human-readable format and [GetMillis](ai2.appinventor.mit.edu/reference/components/sensors.html#Clock.GetMillis){:target="_blank"} for computer-readable formats

## Resources
* [App Inventor documentation](http://ai2.appinventor.mit.edu/reference/components/sensors.html#Clock){:target="_blank"}
* [Overview of date and time patterns](https://docs.oracle.com/javase/7/docs/api/java/text/SimpleDateFormat.html){:target="_blank"}