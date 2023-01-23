docker ps -a |grep -i myweb |cut -d ' ' -f 1 |xargs docker stop
docker ps -a |grep -i myweb |cut -d ' ' -f 1 |xargs docker rm 
docker rmi mywebapplication
docker build -t mywebapplication .
docker tag mywebapplication localhost:5000/mywebapplication
docker push localhost:5000/mywebapplication
docker run -d -p 80:8080 mywebapplication


