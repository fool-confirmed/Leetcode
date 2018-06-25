/*
# Test Docker Features

## create a new webapi project in dotnet cli
-lang|--language
-n|--name
`dotnet new webapi -lang C# -n CoolWhip`

## dotnet publish command
-c|--configuration
`dotnet publish ./CoolWhip/CoolWhip.csproj -c Debug`

## docker build command to create an image
-t tag, a friendly name--lower case only
`docker build -t coolwhip ./CoolWhip`

## run
-p|--publish [host]:[container]
-d|--detach run container in background
`docker run -d --name mytest -p 4000:80 coolwhip`
`docker run --rm -d --name mytest -v c:/data:/data -p 4000:80  coolwhip`

https://rominirani.com/docker-on-windows-mounting-host-directories-d96f3f056a2c

Docker run (-d) runs in detached mode

docker ps :list containers
docker logs mytest :logs of container mytest, covers the standard out of the container

quick note: docker volume

```bash
docker inspect mytest
```

Yields information about the container

Runs an executable on the container, in this case it is interactive (-i), and runs shell (bash)
```bash
docker exec -it mytest bash
```

Remove all stopped containers
```bash
docker rm $(docker ps -qa)
```
*/