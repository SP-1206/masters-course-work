Part - 1 Static website hosting using S3:
I have a created a 2 HTML files named:
first.html, error.html
using a W3.css template and pushed it on to an S3 bucket.
I then enabled static web-hosting on the S3 bucket to provide external access to my website.
The url for the project page:
http://sparavind.s3-website-us-east-1.amazonaws.com/
The website has a hyperlink called Assignment - 1 under the SWE-645 Projects section which takes you to the second part of the assignment - The survey form.




Part - 2 hosting a survey form using Tomcat and EC2:
For the second part of the project I created 2 HTML files - survey.html and Welcome.html and 1 css file using the w3 css templates.
I spun up an EC2 instance and used the bitnami tomcat server image. I then generate a war file with the above HTML files using the command:
jar -cvf g01301679.war *
I then deployed this war file using the tomcat manager GUI.
The url for the survey form:
https://ec2-3-237-46-74.compute-1.amazonaws.com/survey/survey.html

Please note that you might get a message saying that the connection to the url is not private:
please click on: x
Show advanced options
click on "Proceed to ec2-3-237-46-74.compute-1.amazonaws.com (unsafe)"
