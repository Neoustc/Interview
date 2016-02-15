def getIntersectionNode(self, headA, headB):
	p1 = headA
	p2 = headB
	if p1 == None or p2 == None :
		return None
	while (p1 is not None) and (p2 is not None) and (p1 is not p2):
		p1 = p1.next
		p2 = p2.next
		if p1 is p2 :
			return p1
		if p1 is None :
			p1 = headB
		if p2 is None :
			p2 = headA
	return p1
