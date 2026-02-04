



start="2026-02-04"
end="2026-05-02"
current="$start"
while true; do
	echo "update $current" >> log.txt
	git add .
	GIT_AUTHOR_DATE="$current 12:00:00" \
	GIT_COMMITTER_DATE="$current 12:00:00" \
	git commit -m "update on $current"
	if [ "$current"="$end" ]; then
		break
	fi
	current=$(date -d "$current + 1 day" +"%Y-%m-%d")
done
