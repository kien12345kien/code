#!/bin/bash

while true; do
    DATE=$(date)
    CONTENT_LENGTH=$(wc -c <<EOF
<!DOCTYPE html>
<html>
<head>
<title>Page Title</title>
</head>
<body>
Current date is: $DATE
</body>
</html>
EOF
)

    cat <<EOF
HTTP/1.1 200 OK
Connection: close
Date: $DATE
Server: netcat special deal
Content-Length: $CONTENT_LENGTH
Content-Type: text/html; charset=utf-8
Cache-Control: max-age=60

<!DOCTYPE html>
<html>
<head>
<title>Page Title</title>
</head>
<body>
Current date is: $DATE
</body>
</html>
EOF
done

